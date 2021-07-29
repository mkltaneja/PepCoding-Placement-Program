const initialState = {
    numberofBalls: 20
}

const BUY_BALL = 'BUY_BALL';

const BallReducer = (state = initialState, action)=>{
    switch(action.type)
    {
        case BUY_BALL:
            return {...state, numberofBalls: this.initialState.numberofBalls-1};
        default:
            return state;
    }
}

export default BallReducer;