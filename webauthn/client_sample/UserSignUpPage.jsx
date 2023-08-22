import React from 'react';
import { useNavigate } from "react-router-dom";
import NavBar from '../../sections/NavBar/NavBar';
import "./UserSignUpPage.css";
import GLOBAL_VARIABLES from '../../globalVariables';
import { registerUser, registerUserAuthentication, bufferToBase64URLString } from "../../helper/HelperFucntion";
import PAGES from '../../enums';

const server_url = GLOBAL_VARIABLES["python-flask"];
const generate_registration_options_url = server_url + "/generate_registration_options";
const verify_registration_url = server_url + "/verify_registration";

class Page extends React.Component {

    constructor() {
        super();
        this.handleSubmit = this.handleSubmit.bind(this);
        this.registerWebAuthentication = this.registerWebAuthentication.bind(this);
        this.generateRandomDigits = this.generateRandomDigits.bind(this);
    }

    generateRandomDigits() {
        let min = Math.pow(10, 9);
        let max = Math.pow(10, 10) - 1;
        return Math.floor(min + Math.random() * (max - min + 1));
    }

    async handleSubmit(e) {
        e.preventDefault();
        const form = document.forms.userSignUp;
        const firstName = form.firstName.value;
        const lastName = form.lastName.value;
        const userName = firstName + " " + lastName
        const response = await this.registerWebAuthentication(userName);
        const publicKey = response["credential_public_key"];
        const credentialData = JSON.parse(localStorage.getItem('credentialData'));
        const userId = localStorage.getItem('user');

        let routing = "/user-sign-up";
        form.reset();
        if (response.user_verified) {
            console.log("Authentication success");
            routing = PAGES["login-page"];

            const inputuser = {
                id: userId,
                firstName: firstName,
                lastName: lastName,
                postalcode: null,
                address: null,
                email: null,
                phone: null,
                password: null
            };
            var registededData = await registerUser(inputuser);

            const inputAuthentication = {
                user_id: userId,
                credential: credentialData,
                publicKey: publicKey
            }
            var registeredAuth = await registerUserAuthentication(inputAuthentication);
            console.log("registeredAuth: ", registeredAuth);
            form.reset();
            if (registededData) {
                routing = PAGES["login-page"];
                console.log("Navigating to the routing: ", routing);
                this.props.navigate(routing);
            }
        } else {
            console.error("Authentication failed1: ", response.error);
        }
        form.reset();
    }
    
    async registerWebAuthentication(name) {
        const userId = "auth" + this.generateRandomDigits();
        const response = await fetch(generate_registration_options_url, {
            method: 'POST',
            headers: {
            'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                rp_id: "localhost",
                rp_name: "Hirefix",
                user_id: userId,
                user_name: name,
                user_display_name: name
            }),
        });

        const options = await response.json();
        options.challenge = new Uint8Array(options.challenge);
        options.user.id = new Uint8Array(options.user.id);
        options.excludeCredentials = options.excludeCredentials.map(cred => ({
            ...cred,
            id: new Uint8Array(cred.id)
        }));
        try {
            const credential = await navigator.credentials.create({ publicKey: options });
            if (!credential) {
                throw new Error('Registration was not completed');
            }
            // Handle successful registration (e.g., send credential to the server)
            const credentialData = {
                id: credential.id,
                rawId: bufferToBase64URLString(credential.rawId),
                response: {
                    attestationObject: bufferToBase64URLString(credential.response.attestationObject),
                    clientDataJSON: bufferToBase64URLString(credential.response.clientDataJSON),
                    transports: credential.response.getTransports ? credential.response.getTransports() : undefined
                },
                type: credential.type,
                clientExtensionResults: credential.getClientExtensionResults(),
                authenticatorAttachment: credential.authenticatorAttachment
            };
            const verification_response = await fetch(verify_registration_url, {
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
            localStorage.setItem('user', userId);
            localStorage.setItem('challenge', bufferToBase64URLString(options.challenge.buffer));
            localStorage.setItem('credentialData', JSON.stringify(credentialData));
            localStorage.setItem('publicKey', verification_response_json["credential_public_key"]);
            localStorage.setItem('signCount', verification_response_json["sign_count"]);
            console.log("verification_response_json:", verification_response_json);
            return verification_response_json

        } catch (error) {
            console.error('Registration failed:', error);
        }
    }

    render() {
        return (
            <div className='signuppage'>
                <NavBar />
                <div className='signUpPage-container'>
                    <div className='sideCard-container'>
                        <div>
                            <h2>Sign-Up as our User!</h2>
                            <p>We need you to help us with some basic informaton for your account creation</p>
                        </div>
                        <img />
                    </div>
                    <div className="form-container">
                        <form name='userSignUp' onSubmit={this.handleSubmit}>
                            <div className='form'>
                                <div className='left-form'>
                                    <label htmlFor='firstName'>First Name</label>
                                    <input type="text" name='firstName' required />

                                    <label htmlFor="postalCode">Postal Code</label>
                                    <input type="number" name="postalCode" id="" disabled />

                                    <label htmlFor="email">Email</label>
                                    <input type="email" name="email" id="" disabled />

                                    <label htmlFor="password">Set Password</label>
                                    <input type="password" name="password" id="" disabled />
                                </div>

                                <div className='right-form'>
                                    <label htmlFor='lastName'>Last Name</label>
                                    <input type="text" name='lastName' required />

                                    <label htmlFor="address">Address</label>
                                    <input type="address" name="address" id="" disabled />

                                    <label htmlFor="phone">Contact Number</label>
                                    <input type="number" name="phone" id="" disabled />

                                    <label htmlFor="confirmPassword">Confirm Password</label>
                                    <input type="password" name="confirmPassword" id="" disabled />
                                    <label id='mismatchingPassword'>*Mismatching password</label>
                                </div>
                            </div>


                            <p>*By Submitting my details, I state that I have understood and agree to the terms and conditons.</p>
                            {/* <input type="submit" value="Submit" /> */}
                            <input type="submit" value="Registration" />

                        </form>
                    </div>
                </div>
            </div>
        )
    }
}

export default function UserSignUpPage() {

    const navigate = useNavigate()

    return <Page navigate={navigate} />

}