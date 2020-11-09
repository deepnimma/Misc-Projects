const BUTTON = document.getElementById("btn");
const counter = document.getElementById("questions_done");
var questionsDone = 0;

document.addEventListener("click", () => {
    questionsDone += 5;
    counter.innerHTML = questionsDone;
});
