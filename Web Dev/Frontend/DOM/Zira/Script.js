let TC = document.querySelector(".ticket-container");
let allFilters = document.querySelectorAll(".filter");
let modalVisible = false; 
let SelectedPriority = "pink";

for (let i = 0; i < allFilters.length; i++) {
    allFilters[i].addEventListener("click", filterHandler);
    // console.log(allFilters[i]);
}

function filterHandler(e) {

}

let addButton = document.querySelector(".add");

addButton.addEventListener("click", showModal);

function showModal(e)
{
    if(!modalVisible)
    {
        modalVisible = true;
        let modal = `<div class="modal">
                        <div class="task-to-be-added" data-type="false" spellcheck="false" contenteditable="true">
                            <span class="placeholder">Kuch Likhle</span>
                        </div>
                        <div class="priority-list">
                            <div class="pink-modal-filter modal-filter active"></div>
                            <div class="blue-modal-filter modal-filter"></div>
                            <div class="yellow-modal-filter modal-filter"></div>
                            <div class="green-modal-filter modal-filter"></div>
                        </div>
                    </div>`;
        // Adding customized HTML(modal) to the actual HTML
        TC.innerHTML = TC.innerHTML + modal;
        SelectedPriority = "pink";

        // Typing in the ticket
        let taskTyper = document.querySelector(".task-to-be-added");
        taskTyper.addEventListener("click", function(e)
        {
            if(e.currentTarget.getAttribute("data-type") == "false")
            {
                e.currentTarget.innerHTML = "";
                e.currentTarget.setAttribute("data-type","true");
            }
        });

        // Making new ticket with Enter key
        taskTyper.addEventListener("keypress", addTicket.bind(this,taskTyper));


        // Making every color in priority list active
        let modalFilters = document.querySelectorAll(".modal-filter");
        for(let i = 0; i < modalFilters.length; i++)
            modalFilters[i].addEventListener("click", selectPriority);

    }
}

function selectPriority(e)
{
    let activeFilter = document.querySelector(".modal-filter.active");
    activeFilter.classList.remove("active");
    SelectedPriority = e.currentTarget.classList[0].split("-")[0];
    e.currentTarget.classList.add("active");
}

function addTicket(taskTyper, e)
{
    if(e.key == "Enter" && taskTyper.innerText != "")
    {
        let ticket = `<div class="ticket">
                        <div class="ticket-color ticket-color-${SelectedPriority}"></div>
                        <div class="ticket-id"></div>
                        <div class="task">${taskTyper.innerText}</div>
                      </div>`;
        document.querySelector(".modal").remove();
        TC.innerHTML = TC.innerHTML + ticket;
        modalVisible = false;
    }
    else if(e.key == "Enter")
    {
        e.preventDefault();
    }
}


