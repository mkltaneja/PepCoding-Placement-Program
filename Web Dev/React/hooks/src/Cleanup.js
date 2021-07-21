import React, { useState, useEffect } from 'react'

export default function Infinite() {

    console.log("render");

    const [count, setCount] = useState(0);

    useEffect(() => {
        console.log("useEffect");
        document.title = `Clicked ${count} times`

        // cleanup (optional)
        return () => {
            alert(`I will be called before the next useEffect is called ${count}`);
        }
    })

    console.log(count);
    return (
        <div>
            <h1>{count}</h1>
            <button onClick={() => setCount(count + 1)}>Click</button>
        </div>
    )
}
