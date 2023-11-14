import React from 'react'
import {Link} from "react-router-dom";
import {ShoppingCart} from 'phosphor-react';


export default function navbar() {
  return (
    <div className="Navbar">
        <div className="links">
            <Link to= "/shop">Shop</Link>
            <Link to= "/cart">
                <ShoppingCart size={32}/>
            </Link>
        </div>
    </div>
  )
}
