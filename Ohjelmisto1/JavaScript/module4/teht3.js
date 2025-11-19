'use strict';     
const tvform = document.querySelector('#television')
tvform.addEventListener('submit', async function(evt) {     
        evt.preventDefault();
        const code = document.querySelector('input[name=query]').value;
        console.log(code)
        try {
            const response = await fetch(`https://api.tvmaze.com/search/shows?q=${code}`)
            const jsonData = await response.json()
            console.log(jsonData)
            formresults(jsonData)    
        } catch (err) {
            console.log(err.message);
    }
});
function formresults(results) {
    const resultlist = document.getElementById("results");
    resultlist.innerHTML = '';

    results.forEach(result => {
        const article = document.createElement('article');

        const name = document.createElement('h2');
        name.textContent = result.show.name;
        article.appendChild(name);

        const link = document.createElement('a');
        link.href = result.show.url;
        link.target = "_blank";
        link.textContent = result.show.url;
        article.appendChild(link);

        const img = document.createElement("img");
        img.src = result.show.image?.medium ?? '';
        img.alt = result.show.name;
        article.appendChild(img);

        const summary = document.createElement("div");
        summary.innerHTML = result.show.summary;
        article.appendChild(summary);

        resultlist.appendChild(article);
    });
}
