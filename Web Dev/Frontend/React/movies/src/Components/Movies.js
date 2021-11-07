import React, { Component } from 'react'
import { getMovies } from './getMovies'
import axios from 'axios'

export default class Movies extends Component {
    constructor() {
        super();
        this.state = {
            // movies: getMovies(),
            movies: [],
            currText: '',
            currPage: 1,
            items: 0,
            // limit: this.items,
            limit: 5,
        }
        console.log(this);
    }

    async componentDidMount() {
        console.log("Component DID Mount");
        let res = await axios.get("https://backend-react-movie.herokuapp.com/movies");
        this.setState({ movies: res.data.movies });
        console.log(res);
    }

    onDelete = (id) => {
        let arr = this.state.movies.filter(function (moviesObj) {
            return moviesObj._id !== id;
        });
        console.log(arr);
        this.setState({ movies: arr });
    }

    handleChange = (e) => {
        let val = e.target.value;
        // console.log(val);
        this.setState({ currText: val });

    }

    stockAscending = () => {
        let narr = this.state.movies.sort(function (moviesObj1, moviesObj2) {
            return moviesObj1.numberInStock - moviesObj2.numberInStock;
        });
        this.setState({ movies: narr });
        console.log(narr);
    }
    stockDescending = () => {
        let narr = this.state.movies.sort(function (moviesObj1, moviesObj2) {
            return moviesObj2.numberInStock - moviesObj1.numberInStock;
        });
        this.setState({ movies: narr });
    }

    rateAscending = () => {
        let narr = this.state.movies.sort(function (moviesObj1, moviesObj2) {
            return moviesObj1.dailyRentalRate - moviesObj2.dailyRentalRate;
        });
        this.setState({ movies: narr });
    }
    rateDescending = () => {
        let narr = this.state.movies.sort(function (moviesObj1, moviesObj2) {
            return moviesObj2.dailyRentalRate - moviesObj1.dailyRentalRate;
        });
        this.setState({ movies: narr });
    }

    handlePageChange = (pageNum) => {
        this.setState({ currPage: pageNum });
    }

    increment = () => {
        this.setState({
            items: this.state.items + 1,
            limit: this.state.items
        });
    }

    decrement = () => {
        this.setState({
            items: this.state.items - 1,
            limit: this.state.items
        });
    }

    render() {
        console.log("render");

        let { movies, currText, currPage, limit } = this.state;
        let filteredArr = [];
        if (currText == '')
            filteredArr = movies;
        else {
            filteredArr = movies.filter(function (movieObj) {
                let title = movieObj.title.toLowerCase();
                return title.includes(currText.toLowerCase());
            });
        }

        let totpages = Math.ceil(filteredArr.length / limit);
        let pageNumArr = [];
        for (let i = 0; i < totpages; i++)
            pageNumArr.push(i + 1);
        let si = (currPage - 1) * limit;
        let ei = si + limit;
        filteredArr = filteredArr.slice(si, ei);

        return (
            // JSX
            <div className='row'>
                <div className='col-3'>
                    Hello
                </div>
                <div className='col-9'>
                    <input type="search" value={this.state.currText} onChange={this.handleChange}></input>
                    <label for="items">Number of items per page</label>
                    <button onClick={this.decrement}>-</button>
                    <span>{this.state.items}</span>
                    <button onClick={this.increment}>+</button>
                    <table className="table">
                        <thead>
                            <tr>
                                <th scope="col">Title</th>
                                <th scope="col">Genre</th>
                                <th scope="col">
                                    <i className="fas fa-sort-up" aria-hidden="true" onClick={this.stockAscending}></i>
                                    Stock
                                    <i className="fas fa-sort-down" aria-hidden="true" onClick={this.stockDescending}></i>
                                </th>
                                <th scope="col">
                                    <i className="fas fa-sort-up" aria-hidden="true" onClick={this.rateAscending}></i>
                                    Rate
                                    <i className="fas fa-sort-down" aria-hidden="true" onClick={this.rateDescending}></i>
                                </th>
                            </tr>
                        </thead>
                        <tbody>
                            {
                                filteredArr.map((moviesObj) => {
                                    return (
                                        <tr scope='row' key={moviesObj._id}>
                                            <td>{moviesObj.title}</td>
                                            <td>{moviesObj.genre.name}</td>
                                            <td>{moviesObj.numberInStock}</td>
                                            <td>{moviesObj.dailyRentalRate}</td>
                                            <td><button onClick={() => this.onDelete(moviesObj._id)} type='button' className='btn btn-danger'>Delete</button></td>
                                        </tr>
                                    );
                                })
                            }
                        </tbody>
                    </table>
                    <nav aria-label="...">
                        <ul className="pagination">
                            <li className="page-item">
                                <a class="page-link" href="#" aria-label="Previous">
                                    <span aria-hidden="true">&laquo;</span>
                                </a>
                            </li>
                            {
                                pageNumArr.map((pageNum) => {
                                    let classStyle = (pageNum == currPage) ? "page-item active" : "page-item";
                                    return (
                                        <li key={pageNum} className={classStyle} onClick={() => this.handlePageChange(pageNum)}><span className="page-link">{pageNum}</span></li>
                                    )
                                })
                            }
                            <li className="page-item">
                                <a className="page-link" href="#" aria-label="Next">
                                    <span aria-hidden="true">&raquo;</span>
                                </a>
                            </li>
                        </ul>
                    </nav>
                </div>
            </div>
        )
    }
}