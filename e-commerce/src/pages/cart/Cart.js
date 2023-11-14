import React, {useContext} from 'react';
import "./cart.css";
import { PRODUCTS } from '../../products';
import CartItem from './CartItem';
import { ShopContext } from '../../context/shop-context';

export default function Cart() {

  const {cartItems, addToCart} = useContext(ShopContext);
  return (
    <div className="cart">
     
      <div>
        <h1> Your Cart Items</h1>
      </div>

      <div className="classItems">

        {PRODUCTS.map((product) => {
          if(cartItems[product.id] !== 0){
            return <CartItem value={product}/>
          }
        })}

      </div>
    </div>
  )
}
