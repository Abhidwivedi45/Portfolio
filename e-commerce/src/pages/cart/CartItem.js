import React, { useContext } from 'react'

import { ShopContext } from '../../context/shop-context';

export default function CartItem(props) {
    const {id, productName, price, productImage} = props.value;
    const {cartItems, addToCart, removeFromCart} = useContext(ShopContext)

  return (
    <div className= "cartItem">
        <img src={productImage}/>
        <div className='description'>
            <p><b>{productName}</b></p>
            <p>${price}</p>
            <div className= "count Handler">
                <button onClick={() => removeFromCart(id)}> - </button>
                <input value= {cartItems[id]} />
                <button  onClick={()=> addToCart(id)}> + </button>
            </div>
        </div>
    </div>
  )
}
