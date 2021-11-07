import {createStore} from 'redux';
import {composeWithDevTools} from 'redux-devtools-extension';
import BallReducer from "./Balls/BallReducer";

const store = creatStore(BallReducer, composeWithDevTools());

export default store;