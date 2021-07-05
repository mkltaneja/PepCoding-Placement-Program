import react, { useState } from 'react'

function Counter() {
    console.log("Render")
    // this.state = {
    //     count: 0
    // }

    const [count, setCount] = useState(0);

    const handleIncrement = () => {
        setCount(count + 1);
    }
    const handleDecrement = () => {
        setCount(count - 1);
    }

    return (
        // JSX
        <div>
            <h1>{count}</h1>
            <button onClick={handleIncrement}>+</button>
            <br />
            <button onClick={handleDecrement}>-</button>
        </div>
    )
}


export default Counter