import React, { useState, useContext } from 'react'
import { AuthContext } from '../Context/AuthProvider';

export default function Login() {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [error, setError] = useState('');
    const [loading, setLoading] = useState(false);

    let { login } = useContext(AuthContext);

    const handleLogin = async () => {
        try {
            setLoading(true);
            await login(email, password);
        }
        catch(err) 
        {
            setError(err.message);
            setTimeout(()=>setError(''), 5000);
            setLoading(false);
        }
        setLoading(false);
    }

    return (
        <div>
            <label htmlFor=''>Email</label>
            <input type='text' value={email} onChange={(e) => setEmail(e.target.value)}></input>
            <label htmlFor=''>Password</label>
            <input type='text' value={password} onChange={(e) => setPassword(e.target.value)}></input>
            <button type='submit' onClick={handleLogin} disabled={loading}>Login</button>
            {error? <h1>{error}</h1>: <></>}
        </div>
    )
}
