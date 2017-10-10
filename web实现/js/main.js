window.onload = function(){
    var button = document.getElementsByTagName("button");

}

function encrypt(){
    var encrypt = document.getElementById("encrypt"),
        input = encrypt.getElementsByTagName("input"),
        key = input[0].value;
        plain_text = input[1].value;

    encryptAlgorithm(key,plain_text);
}


function encryptAlgorithm(key,plain_text){
    
}