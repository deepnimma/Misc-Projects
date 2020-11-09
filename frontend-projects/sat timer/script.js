const reading = document.getElementById("sat-reading");
const writing = document.getElementById("sat-writing");
const nocalc = document.getElementById("sat-nocalc");
const calc = document.getElementById("sat-calc");

const hourshtml = document.getElementById("hours")
const minuteshtml = document.getElementById("mins")
const secondshtml = document.getElementById("seconds")

function countdown(secs) {
    while(secs != 0) {
        const totalSeconds = secs;
  
        // const days = Math.floor(totalSeconds / 3600 / 24);
        const hours = Math.floor(totalSeconds / 3600) % 24;
        const mins = Math.floor(totalSeconds / 60) % 60;
        const seconds = Math.floor(totalSeconds) % 60;
  
        // daysEl.innerHTML = days;
        hourshtml.innerHTML = formatTime(hours);
        minuteshtml.innerHTML = formatTime(mins);
        secondshtml.innerHTML = formatTime(seconds);

        secs--;
        // setTimeout(1000000000)
        clearTimeout(1000)
    }

    for(var start = seconds; start > 0; start--) {
        setTimeout(function () {
            const totalSeconds = start;
  
        // const days = Math.floor(totalSeconds / 3600 / 24);
        const hours = Math.floor(totalSeconds / 3600) % 24;
        const mins = Math.floor(totalSeconds / 60) % 60;
        const seconds = Math.floor(totalSeconds) % 60;
  
        // daysEl.innerHTML = days;
        hourshtml.innerHTML = formatTime(hours);
        minuteshtml.innerHTML = formatTime(mins);
        secondshtml.innerHTML = formatTime(seconds);

        secs--;
        
        }, 1000);
      }
}

function formatTime(time) {
    return time < 10 ? `0${time}` : time;
}

reading.addEventListener("click", () => {
    document.body.style.background = randomBg();
});

writing.addEventListener("click", () => {
    countdown(2100);
});

nocalc.addEventListener("click", () => {
    document.body.style.background = randomBg();
});

calc.addEventListener("click", () => {
    document.body.style.background = randomBg();
});
