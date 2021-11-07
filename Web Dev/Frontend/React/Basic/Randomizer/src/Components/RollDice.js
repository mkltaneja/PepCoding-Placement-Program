import React, { useState } from 'react';
import Die from "./Die.js";
import "./RollDice.css";


function Roll


// const RollDice = () => {

//     var num1 = 5, num2 = 6, score = 0;
//     const map = {
//         "one": 1,
//         "two": 2,
//         "three": 3,
//         "four": 4,
//         "five": 5,
//         "six": 6,
//         1: "one",
//         2: "two",
//         3: "three",
//         4: "four",
//         5: "five",
//         6: "six"
//     };

//     const [ state, setState ] = useState({ num1: 5, num2: 6, score: 0 });

//     const handleRoll = () => {
//         let nnum1 = Math.floor(Math.random() * 6) + 1;
//         let nnum2 = Math.floor(Math.random() * 6) + 1;
//         let nscore = score + (num1 == num2) ? num1 : 0;
//         console.log(nnum1, nnum2, nscore);
//         setState({ num1: nnum1, num2: nnum2, score: nscore });
//     }

//     return (
//         <>
//         {/* render() */}
//             <div className="dice">
//                 <Die face={map[num1]} />
//                 <Die face={map[num2]} />
//             </div>
//             <div className="controls">
//                 <button type="button" className="btn btn-dark" onClick={handleRoll}>Roll Dice</button>
//                 <div className="Answer">Your score is - {score}</div>
//                 <h1>{num1}</h1>
//                 <h1>{num2}</h1>
//                 <h1>{score}</h1>
//             </div>
//         </>
//     );
// };

export default RollDice;