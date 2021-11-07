import './App.css';
import store from './Redux/Store'
import BallContainer from './BallContainer'
import { Provider } from 'react-redux';

function App() {
  return (
    <Provider store={store}>
      <div className="App">
        <BallContainer />
      </div>
    </Provider>
  );
}

export default App;
