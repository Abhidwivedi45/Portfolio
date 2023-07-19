

for(var i=0; i<document.querySelectorAll(".drum").length; i++){
    document.querySelectorAll(".drum")[i].addEventListener("click", function() {
        var bword = this.innerHTML;
        sound(bword);
        anim(bword);
});
}

document.addEventListener("keypress", function(event){
    sound(event.key);
    anim(event.key);
});

function sound(key){
    switch (key) {
        case "w":
            var audio= new Audio('sounds/tom-1.mp3');
            audio.play();
            break;

        case "a":
            var budio= new Audio('sounds/tom-2.mp3');
            budio.play();
            break;

        case "s":
            var cudio= new Audio('sounds/tom-3.mp3');
            cudio.play();
            break;
                
        case "d":
            var dudio= new Audio('sounds/tom-4.mp3');
            dudio.play();
            break;
            
        case "j":
            var eudio= new Audio('sounds/snare.mp3');
            eudio.play();
            break;

        case "k":
            var fudio= new Audio('sounds/kick-bass.mp3');
            fudio.play();
            break;

        case "l":
            var gudio= new Audio('sounds/crash.mp3');
            gudio.play();
            break;


        default:
            console.log(key);

    }
}

function anim(key){
    document.querySelector("."+key).classList.add("pressed");

    setTimeout(function(){
        document.querySelector("."+key).classList.remove("pressed");
    }, 100);

}
