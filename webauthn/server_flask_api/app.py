import logging, json
from flask import Flask, request, jsonify
from flask_cors import CORS, cross_origin
from webauthn import (
    generate_registration_options,    
    verify_registration_response,
    generate_authentication_options,
    verify_authentication_response,
    options_to_json,
    base64url_to_bytes,
)
from webauthn.helpers.cose import COSEAlgorithmIdentifier
from webauthn.helpers.structs import (
    AttestationConveyancePreference,
    AuthenticatorAttachment,
    AuthenticatorSelectionCriteria,
    PublicKeyCredentialDescriptor,
    ResidentKeyRequirement,
    RegistrationCredential,
    UserVerificationRequirement,
    AuthenticationCredential,
)

app = Flask(__name__)
cors = CORS(app, origins=['http://localhost:3000'])

@app.route('/generate_registration_options', methods=['POST'])
def generate_complex_options():
    logging.info("generate_complex_options Start")
    data = request.json
    complex_registration_options = generate_registration_options(
        rp_id= data["rp_id"],
        rp_name= data["rp_name"],
        user_id= data["user_id"],
        user_name= data["user_name"],
        user_display_name= data["user_display_name"],
        attestation=AttestationConveyancePreference.DIRECT,
        # authenticator_selection=AuthenticatorSelectionCriteria(
        #     # authenticator_attachment=AuthenticatorAttachment.PLATFORM, # only device
        #     authenticator_attachment=AuthenticatorAttachment.CROSS_PLATFORM,
        #     # resident_key=ResidentKeyRequirement.REQUIRED,
        # ),
        challenge="dG90YWxseXJhbmRvbXZhbHVl",
        exclude_credentials=[
            PublicKeyCredentialDescriptor(id=b"1234567892"),
        ],
        supported_pub_key_algs=[
            COSEAlgorithmIdentifier.ECDSA_SHA_512,
            COSEAlgorithmIdentifier.ECDSA_SHA_256,  # Add this line
            COSEAlgorithmIdentifier.RSASSA_PKCS1_v1_5_SHA_256,  # Add this line
        ],
        timeout=30000,
    )

    logging.info("generate_complex_options End")
    return options_to_json(complex_registration_options)

@app.route('/verify_registration', methods=['POST'])
@cross_origin()
def verify_registration():
    logging.info("verify_registration Start")
    data = request.json
    credential_data = data["credential"]
    credential_json = json.dumps(credential_data)
    
    registration_verification = verify_registration_response(
        credential=RegistrationCredential.parse_raw(credential_json),
        expected_challenge=base64url_to_bytes(data["expectedChallenge"]),
        expected_origin=data["expectedOrigin"],
        expected_rp_id=data["expectedRpId"],
        require_user_verification=True,
    )
    logging.info("verify_registration End")
    return registration_verification.json(indent=2)

@app.route('/generate_auth_options', methods=['POST'])
@cross_origin()
def generate_auth_options():
    logging.info("generate_authentication_options Start")
    data = request.json
    stored_credential_data = data.get("stored_credential_data", {})    
    id_bytes = base64url_to_bytes(stored_credential_data.get("id", ""));
    stored_descriptor = PublicKeyCredentialDescriptor(
        id=id_bytes, 
        type="public-key",
        transports=stored_credential_data.get("transports", [])
    )
    
    complex_authentication_options = generate_authentication_options(
        rp_id=data["rp_id"],
        challenge=bytes(data["challenge"], "utf-8"),
        timeout=30000,
        allow_credentials=[stored_descriptor],
        user_verification=UserVerificationRequirement.REQUIRED,
    )
    logging.info("complex_authentication_options: %s", options_to_json(complex_authentication_options))
    logging.info("generate_authentication_options End")
    return options_to_json(complex_authentication_options)

@app.route('/verify_authentication_response', methods=['POST'])
@cross_origin()
def verify_authentication():
    logging.info("verify_authentication Start")
    data = request.json
    credential_data = data["credential"]
    credential_public_key = credential_data["publicKey"]
    credential_current_sign_count = int(credential_data["signCount"])
    credential_json = json.dumps(credential_data)
    
    registration_verification = verify_authentication_response(
        credential=AuthenticationCredential.parse_raw(credential_json),
        expected_challenge=base64url_to_bytes(data["expectedChallenge"]),
        expected_origin=data["expectedOrigin"],
        expected_rp_id=data["expectedRpId"],
        credential_public_key=base64url_to_bytes(credential_public_key),
        credential_current_sign_count=credential_current_sign_count,
        require_user_verification=True,
    )
    logging.info("verify_registration End")
    return registration_verification.json(indent=2)

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    app.run(debug=True)
