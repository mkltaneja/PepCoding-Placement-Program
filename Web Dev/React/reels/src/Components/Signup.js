import React, { useState, useEffect, useContext } from 'react';
import { AuthContext } from '../Context/AuthProvider';
import { storage, database } from '../Firebase';

function Signup() {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [name, setName] = useState('');
    const [error, setError] = useState('');
    const [loading, setLoading] = useState(false);
    const [file, setFile] = useState(null);

    const { signup } = useContext(AuthContext);

    const handleSignUp = async (e) => {
        e.preventDefault();
        try {
            setLoading(true);
            let res = await signup(email, password);
            console.log(res);
            let uid = res.user.uid;
            console.log(uid);

            // console.log(storage.ref(`/users/${uid}/profileImage`));
            console.log(file);
            const uploadTaskListener = storage.ref(`/users/${uid}/profileImage`).put(file);
            console.log(uploadTaskListener);
            // Register 3 observers:- 
            // 1. 'state_changed' observer -> called any time the state is changed
            // 2. Error observer -> called on failure
            // 3. Completion observer -> called on successful completion

            // fn1 -> progress tracking
            // fn2 -> error
            // fn3 -> success

            uploadTaskListener.on('state_changed', fn1, fn2, fn3);

            function fn1(snapshot) {
                console.log(snapshot.bytesTransferred);
                console.log(snapshot.totalBytes);
                var progress = (snapshot.bytesTransferred / snapshot.totalBytes) * 100;
                console.log('Upload is ' + progress + '% done');
            }
            function fn2(error) {
                setError(error);
                setTimeout(() => {
                    setError('')
                }, 2000);
                setLoading(false);
            }
            async function fn3() {
                let downloadUrl = await uploadTaskListener.snapshot.ref.getDownloadURL();
                console.log(downloadUrl);

                await database.users.doc(uid).set({
                    email: email,
                    userId: uid,
                    username: name,
                    createdAt: database.getCurrentTimeStamp(),
                    profileUrl: downloadUrl,
                    postIds: []
                })
                setLoading(false);
                console.log("Uses has Signed Up");
            }
        }
        catch (err) {
            setError(err);
            setTimeout(() => setError(''), 2000);
            setLoading(false);
        }
    }

    const handleFileSubmit = async (e) => {
        let file = e.target.files[0];
        console.log(file);
        if (file != null) {
            setFile(file);
        }
    }

    return (
        <div>
            <form onSubmit={handleSignUp}>
                <div>
                    <label htmlFor=''>User Name</label>
                    <input type='text' value={name} onChange={(e) => setName(e.target.value)}></input>
                </div>
                <div>
                    <label htmlFor=''>Email</label>
                    <input type='text' value={email} onChange={(e) => setEmail(e.target.value)}></input>
                </div>
                <div>
                    <label htmlFor=''>Password</label>
                    <input type='text' value={password} onChange={(e) => setPassword(e.target.value)}></input>
                </div>
                <div>
                    <label htmlFor='profile'>Profile Image</label>
                    <input type='file' accept='image/*' onChange={handleFileSubmit}></input>
                </div>
                <button type='submit' disabled={loading}>SignUp</button>
            </form>
        </div>
    )
}

export default Signup;