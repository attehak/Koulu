'use strict';
const names = ['John', 'Paul', 'Jones'];
let list = document.querySelector("#target")

for (let x = 0; x < names.length; x++){
    let li = document.createElement('li')
    li.innerText = names[x]
    list.appendChild(li)
}
