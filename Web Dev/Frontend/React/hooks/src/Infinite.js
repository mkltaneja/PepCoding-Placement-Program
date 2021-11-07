import React, {useState, useEffect} from 'react'

export default function Infinite() {
    console.log("render");

    const [count, setCount] = useState(0);
    console.log(count);

    useEffect(()=>{
        console.log("useEffect");
        let num = Math.random()*100;
        setCount(num);  // If we call for render in the useEffect, then there will be infinite calls to render and useEffect, as 1st render is run, then useEffect
    },[])


    console.log(count);
    return (
        <div>
            <h1>{count}</h1>
            <button onClick={() => setCount(count + 1)}>Click</button>
        </div>
    )
}
