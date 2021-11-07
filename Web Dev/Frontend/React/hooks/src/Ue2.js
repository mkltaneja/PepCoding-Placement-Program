import React, { useState, useEffect } from 'react'

// 2nd variation -> useEffect is run just for the first time

function Ue2() {

    useEffect(() => {
        console.log('useEffect');
        document.title = `Clicked ${count} times`
    },[]);
    console.log("render");
    const [count, setCount] = useState(0);
    return (
        <div>
            <p>You Clicked the button {count} times</p>
            <button onClick={() => { setCount(count + 1) }}>Click</button>
        </div>
    )
}

export default Ue2;