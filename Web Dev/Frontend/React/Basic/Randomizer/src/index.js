import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import 'bootstrap/dist/css/bootstrap.min.css';

ReactDOM.render(
    <App />,
  document.getElementById('main')
);


































// // If you want to start measuring performance in your app, pass a function
// // to log results (for example: reportWebVitals(console.log))
// // or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
// reportWebVitals();


// import React, { PureComponent } from "react";
// import ReactDOM from "react-dom";
// import Lib from "../src/index.js";

// class Main extends PureComponent {
//   handleAudioEncode = file => {
//     console.log(file);
//   };
//   encodeAudio = () => {
//     this.encoder.encodeAudio();
//   };
//   ReactDOM.render() {
//     return (
//       <div className="page-container">
//         <Lib
//           timeLimit={50}
//           onAudioEncode={this.handleAudioEncode}
//           ref={el => (this.encoder = el)}
//         />
//         {/* <span onClick={this.encodeAudio}>Encode</span> */}
//       </div>
//     );
//   }
// }

// ReactDOM.render(<App />, document.getElementById("root"));
// module.hot.accept();