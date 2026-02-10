import React from 'react';
import logo from './logo.svg';
import './App.css';
import Users from './Users';
import {Route, Routes, Link} from 'react-router-dom';
import Home from './Home';
import About from './About';
import Profile from './Profile';
import Articles from './Articles';
import Article from './Article';
import Layout from './Layout';
import ReactDOM from 'react-dom';

interface ProfileData {
    [key: string]: {
        name: string;
        description: string;
    };
}
const App = () => {
    let node = document.getElementById("node");
    let a = ReactDOM.findDOMNode(node);  // @violation

    return (
        <Routes>
            <Route element={<Layout/>}>
                <Route index path="/" element={<Home />} />
                <Route path="/about" element={<About />} />
                <Route path="/profiles/:username" element={<Profile />} />
            </Route>
            <Route path="/articles" element={<Articles />}>
                <Route path=":id" element={<Article />} />
            </Route>
        </Routes>
    );
};

export default App;