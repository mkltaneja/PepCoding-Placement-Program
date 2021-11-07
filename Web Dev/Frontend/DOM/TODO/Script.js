let input = document.querySelector(".task-input");
let ul = document.querySelector(".task-list");

input.addEventListener("keypress", function(e){
    console.log(e);
    if(e.key == "Enter")
    {
        let task = input.value;
        if(task == "")
        {
            alert("Kuch likh to le chutiye");
            return;
        }
        console.log(task);
        input.value = "";

        // For Inserting the tasks at the end of list

        // let li = document.createElement("li");
        // li.innerText = task;
        // ul.appendChild(li);

        // For Inserting the tasks at the end of list

        // -> Method 1
        let li = `<li>${task}</li>`;
        console.log(li);
        let mli = ul.innerHTML;
        console.log(mli);
        let finalHTML = li + mli;
        ul.innerHTML = finalHTML;

        // // Method 2
        // let li = document.createElement("li");
        // li.innerText = task;
        // li.addEventListener("dbllclick", taskDeleter);
    }
}); 