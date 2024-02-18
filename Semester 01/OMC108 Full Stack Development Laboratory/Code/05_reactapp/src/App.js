import logo from './logo.svg';
import logo_geu from './GEU.jpeg';
import './App.css';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <img src={logo_geu} className="geu-logo" alt="logo" height="200" />
        <p>
          {/* Edit <code>src/App.js</code> and save to reload. */}
          Developing using React.JS, Graphic Era University.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          {/* Learn React */}
        </a>
      </header>
    </div>
  );
}

export default App;
