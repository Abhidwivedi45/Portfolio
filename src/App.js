import React from 'react';
//import UilReact from '@iconscout/react-unicons/icons/uil-react'
import './App.css';
import TopButtons from './components/TopButtons';
import Inputs from './components/inputs';
import TimeandLocation from './components/TimeandLocation';
import Temperature from './components/Temperature';
import Forecast from './components/Forecast';
import getFormattedWeatherData from './components/services/eatherService';
import { useState } from 'react';
import { useEffect } from 'react';
import { ToastContainer , toast} from 'react-toastify';
import 'react-toastify/dist/ReactToastify.css';



function App() {

  const [query, setQuery] = useState({q: 'pune'});
  const [units, setUnits] = useState('metric');
  const [weather, setWeather] = useState(null);
 
  useEffect(() => {

    const fetchweather = async  () => {
      const message = query.q ? query.q : "current location"

      toast.info("Fetching Weather for " + message);

     await getFormattedWeatherData( {...query, units}).then(
      (data) => {

        toast.success(`Successfully feathed weather for ${data.name}, ${data.country}.`)
        setWeather(data);
      }
     ); 
  
     
    };
    fetchweather();
  }, [query, units]);

  const formatBackground = () => {
    if(!weather) return "from-cyan-700 to-blue-700";
    const threshold = units === "metric" ? 20 : 60;
    if(weather.temp <= threshold) return "from-cyan-700 to-blue-700"

    return "from-yellow-700 to-orange-700";
  }

 /*
  const fetchweather = async  () => {
     const data = await getFormattedWeatherData( {q: "london"})
      
    
  
     console.log(data);
    };

    fetchweather();
  
    */
   //const dta= weather.hourly;
  console.log(weather);
  // const {details} = weather;
  // console.log(details);

  return (
    <div className={`mx-auto max-w-screen-md mt-4 py-5 px-32 bg-gradient-to-br h-fit shadow-xl shadow-gray-400 ${formatBackground()}`}>
      <TopButtons setQuery={setQuery}/>
      <Inputs setQuery={setQuery} units={units} setUnits={setUnits}/>

      
     {weather && (
      <div>
        <TimeandLocation weather={weather}/>
        <Temperature weather={weather}/>
        <Forecast title="hourly forecast" items={weather.daily}/>

        <Forecast title="Daily Forecast" items={weather.daily}/>
      </div>
     )}
     
    <ToastContainer autoClose={5000} theme='colored' newestOnTop={true}/>
    </div>

  );
}


export default App;
