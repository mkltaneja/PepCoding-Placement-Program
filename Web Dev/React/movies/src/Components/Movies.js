import React, {Component} from 'react'
import { getMovies } from './getMovies'

export default class Movies extends Component
{
    constructor()
    {
        super();
        this.state = {
            movies: getMovies()
        }
    }
    render()
    {
        return (<div></div>)
    }
}