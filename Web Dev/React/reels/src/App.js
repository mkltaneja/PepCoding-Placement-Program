import './App.css';
import AuthProvider from './Context/AuthProvider'
import Signup from './Components/Signup';
import Login from './Components/Login';

function App() {
  return (
    <AuthProvider>
      {/* <Signup /> */}
      <Login />
    </AuthProvider>
    // <Main />
  );
}

export default App;
