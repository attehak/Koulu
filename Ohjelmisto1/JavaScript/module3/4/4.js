'use strict';
const students = [
  {
    name: 'John',
    id: '2345768',
  },
  {
    name: 'Paul',
    id: '2134657',
  },
  {
    name: 'Jones',
    id: '5423679',
  },
];
const options = document.querySelector("#target")
  
for (let x = 0; x < students.length; x++){
  let op = new Option(students[x].name, students[x].id)
  options.appendChild(op)
}
