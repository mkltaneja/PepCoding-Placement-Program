import React, { useState, useEffect } from 'react'
import "./Ue3.css"

// 3rd variation -> Whenever the dependency list is altered, then useEffect is run

function Ue3() {

    const [count, setCount] = useState(0);
    const [darkMode, setDarkMode] = useState(false);

    useEffect(() => {
        console.log('useEffect');
        document.title = `Clicked ${count} times`;
    }, [count]);

    console.log("render");
    
    return (
        <div className={darkMode ? "view dark-mode" : "view"}>
            <label htmlFor="dark Mode">Dark Mode</label>
            <input type="checkbox" checked={darkMode} onChange={() => setDarkMode(!darkMode)} />
            <button onClick={() => { setCount(count + 1) }}>{count}</button>
        </div>
    )
}

export default Ue3;