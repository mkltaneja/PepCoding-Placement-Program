import react from 'react';
import {buyBall} from './Redux/Balls/BallActions';
import {connect} from 'react-redux';

function BallContainer(props)
{
    return (
        <div>
            <h2>Number of Balls = {props.numberofBalls}</h2>
            <button onClick={props.buyBall}>Buy Balls</button>
        </div>
    )
}

// First method for reading from global state
const mapStateToProps = state =>{
    return {
        numberofBalls: state.numberofBalls
    }
}

const mapDispatchToProps = dispatch =>{
    return {
        buyBall: ()=> dispatch(buyBall())
    }
}

export default connect(mapStateToProps, mapDispatchToProps)(BallContainer);