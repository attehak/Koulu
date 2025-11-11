const list = document.querySelector("#target");

function addElem(elemz){
    let li = document.createElement('li')
    li.textContent = elemz
    return li}

let li = document.createElement('li')
li.textContent = "Second item"
li.classList.add("my-item")

list.appendChild(addElem('First item'))
list.appendChild(li)
list.appendChild(addElem('Third item'))
