import React, {useContext} from 'react';
import "./shop.css";
import { ShopContext } from '../../context/shop-context';

export default function Product(props) {
    const { id, productName, price, productImage } = props.data;

    const {cartItems, addToCart}= useContext(ShopContext);

    const itemAmount=  cartItems[id];

  return (
    <div className="product">

        <img src={productImage} />

        <div className='description'>
            <p><b>{productName} </b> </p>
            <p>${price}</p>
        </div>
      <button className='addToCartBttn' onClick= {() => addToCart(id)}>
        Add To Cart { itemAmount > 0 && <> ({itemAmount}) </> }
      </button>

    </div>
  )
}
