import React from 'react'
import NavBar from '../../sections/NavBar/NavBar';
import { useNavigate } from "react-router-dom";
import PAGES from "../../enums";
import GLOBAL_VARIABLES from '../../globalVariables';
import { getUserAuthentication, bufferToBase64URLString } from "../../helper/HelperFucntion";
import "./LoginPage.css";
const server_url = GLOBAL_VARIABLES["python-flask"];
const generate_authentication_options_url = server_url + "/generate_auth_options";
const verify_authentication_url = server_url + "/verify_authentication_response";

class Page extends React.Component {

    constructor() {
        super();
        this.handleSubmit = this.handleSubmit.bind(this);
        this.authenticateWebAuthentication = this.authenticateWebAuthentication.bind(this);
        this.base64URLStringToBuffer = this.base64URLStringToBuffer.bind(this);
    }

    base64URLStringToBuffer(base64URLString) {
        let base64String = base64URLString.replace(/-/g, '+').replace(/_/g, '/');
        let raw = window.atob(base64String);
        let buffer = new Uint8Array(raw.length);
        for (let i = 0; i < raw.length; i++) {
            buffer[i] = raw.charCodeAt(i);
        }
        return buffer;
    }

    async handleSubmit(e) {
        e.preventDefault();
        let authResp;
        try {
            authResp = await this.authenticateWebAuthentication();
            console.log("Authentication response: ", JSON.stringify(authResp, null, 2));
            this.props.navigate(PAGES["user-home-page"]);
        } catch (error){
            console.log("Authentication failed1: ", error.message);
        }
    }

    async authenticateWebAuthentication() {
        const userId = localStorage.getItem("user");
        const userAuth = await getUserAuthentication(userId);
        const storedCredentialData = JSON.parse(localStorage.getItem('credentialData')); // NEED TO MODIFY SCHEMA
        const publicKey = userAuth.publicKey;
        const signCount = localStorage.getItem('signCount');
        let challenge = localStorage.getItem('challenge');
        const response = await fetch(generate_authentication_options_url, {
            method: 'POST',
            headers: {
            'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                rp_id: "localhost",
                challenge: challenge,
                stored_credential_data: storedCredentialData
            }),
        });
        const options = await response.json();
    
        // Convert options to proper format
        options.challenge = new Uint8Array(options.challenge);
        options.allowCredentials = options.allowCredentials.map(cred => ({
            ...cred,
            id: this.base64URLStringToBuffer(cred.id),
        }));

        try {
            const credential = await navigator.credentials.get({ publicKey: options });
            if (!credential) {
                throw new Error('Authentication was not completed');
            }
            const credentialData = {
                id: credential.id,
                rawId: bufferToBase64URLString(credential.rawId),
                response: {
                    authenticatorData: bufferToBase64URLString(credential.response.authenticatorData),
                    clientDataJSON: bufferToBase64URLString(credential.response.clientDataJSON),
                    signature: bufferToBase64URLString(credential.response.signature),
                    userHandle: bufferToBase64URLString(credential.response.userHandle),
                },
                type: credential.type,
                publicKey: publicKey,
                signCount: signCount,
                clientExtensionResults: credential.getClientExtensionResults(),
            };
    
            const verification_response = await fetch(verify_authentication_url, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    credential: credentialData,
                    expectedChallenge: bufferToBase64URLString(options.challenge.buffer),
                    expectedOrigin: window.location.origin,
                    expectedRpId: "localhost",
                }),
            });
            const verification_response_json = await verification_response.json();
            console.log("verification_response_json:", verification_response_json);
            return verification_response_json;
    
        } catch (error) {
            console.error('Authentication failed:', error);
        }
    }

    render() {
        return (
            <div className='login-page'>
                <NavBar />
                <div className='login-container'>
                    <img alt="" />
                    <form name='login' onSubmit={this.handleSubmit}>
                        <h2>FIDO2 Authentication</h2>
                        <label htmlFor="userid">Userid</label>
                        <input type="userid" name="userid" placeholder='User ID' disabled/>
                        <label htmlFor='userType'>Log in as:</label>
                        <input type="submit" value="Webauthn Authentication" />
                    </form>
                </div>
            </div>
        )
    }
}

export default function LoginPage() {
    return <Page navigate={useNavigate()} />
}