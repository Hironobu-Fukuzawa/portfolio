var maxtaskidOutstanding=0;
var maxtaskidCompleted=0;
var localStorage="";

function bootstrap()
{
    // get local storage data
    var storedOutstandingTasks = JSON.parse(localStorage.getItem('outstandingtasks'));
    var storedCompletedTasks = JSON.parse(localStorage.getItem('completedtasks'));
    var tableBodyOst = document.querySelector('#displayoutstanding tbody');
    var tableBodyComp = document.querySelector('#displaycompleted tbody');

    // insert both tasks after loading
    insertTaskFunction(storedOutstandingTasks, tableBodyOst, "outstandingtask_");
    insertTaskFunction(storedCompletedTasks, tableBodyComp , "completedtask_");
    maxtaskidOutstanding = (storedOutstandingTasks == null)? 0: storedOutstandingTasks.length;
    maxtaskidCompleted = (storedCompletedTasks == null)? 0: storedCompletedTasks.length;    

    // initialize the display
    document.getElementById('display').style.display = "block";
}

function taskManagementFunction(){
    var currenttasks = JSON.parse(localStorage.getItem('outstandingtasks'));
    var completedtasks = JSON.parse(localStorage.getItem('completedtasks'));
    lenCur = (currenttasks == null)? 0: currenttasks.length;
    lenComp = (completedtasks == null)? 0: completedtasks.length;
    var percentage = document.getElementById("percentage");
    var completionRate = (lenComp != 0)? (lenComp / (lenCur + lenComp)) * 100: 0;
    percentage.textContent = Math.floor(completionRate)  + "%";

    // filter ongoing task within one week
    var oneWeekFromNow = new Date();
    oneWeekFromNow.setDate(oneWeekFromNow.getDate() + 7);
    if(lenCur > 0){
        var oncomingTasks = currenttasks.filter(function(task) {
            return new Date(task.deadline) <= oneWeekFromNow;
          });
          taskCount.textContent = oncomingTasks.length;      
    } else{
        taskCount.textContent = 0;
    }
}

function addfunction()
{
    var outstandingtask = [];
    var task = document.getElementById("task").value;
    var priority = document.getElementById("priority").value;
    var deadline = document.getElementById("deadline").value;
    var table = document.getElementById("displayoutstanding");

    maxtaskidOutstanding += 1;
    outstandingtask.push({
        id: maxtaskidOutstanding,
        task: task,
        priority: priority,
        deadline: deadline
      });

    // initialization for the display
    document.getElementById('add').style.display = "none";
    document.getElementById('display').style.display = "block";

    // insert the data
    insertTaskFunction(outstandingtask, table, "outstandingtask_");

    // update localstorage
    var storedOutstandingTasks = JSON.parse(localStorage.getItem('outstandingtasks'));
    if(storedOutstandingTasks != null) {
        storedOutstandingTasks.push(outstandingtask[0]);
        localStorage.setItem('outstandingtasks', JSON.stringify(storedOutstandingTasks));  
    }else {
        localStorage.setItem('outstandingtasks', JSON.stringify(outstandingtask));  
    }
}

function finishfunction()
{
    // variables
    var serialId = document.getElementById("serialId").value;
    var oustandingtasks = JSON.parse(localStorage.getItem('outstandingtasks'));
    var completedtasks = JSON.parse(localStorage.getItem('completedtasks'));

    // remove the target task within outstandingtasks
    document.getElementById("outstandingtask_" + serialId).remove();
    
    var addCompletedTask = [];

    for (var i = 0; i < oustandingtasks.length; i++) {
        if(oustandingtasks[i].id == serialId){
            addCompletedTask = oustandingtasks[i];
            oustandingtasks.splice(serialId - 1, 1);
        }
    }

    for (var i = 0; i < oustandingtasks.length; i++) {
        oustandingtasks[i].id = i + 1;
        console.log("oustandingtasks[i].id : ", oustandingtasks[i].id);
    }

    maxtaskidCompleted += 1;
    maxtaskidOutstanding -= 1;
    if(completedtasks == null){
        completedtasks = [];
    }

    completedtasks.push({
        id: maxtaskidCompleted,
        task: addCompletedTask.task,
        priority: addCompletedTask.priority,
        deadline: addCompletedTask.deadline
    });

    // initialization for the display
    document.getElementById('finish').style.display = "none";
    document.getElementById('display').style.display = "block";

    // update localstorage
    localStorage.setItem('outstandingtasks', JSON.stringify(oustandingtasks));  
    localStorage.setItem('completedtasks', JSON.stringify(completedtasks));  

    // reload the page to initialize the table rows
    location.reload();
}

function displayfunction(element)
{
    var displayList = ["home", "add", "finish", "display"];
    for (var i = 0; i < displayList.length; i++) {
        if(displayList[i] == element){
            document.getElementById(element).style.display = "block";
        }else{
            document.getElementById(displayList[i]).style.display = "none";
        }
    }
    if(element == "home"){
        document.getElementById("display").style.display = "block";
    }
}

function insertTaskFunction(array, tbody, idName){
    if(array != null){
        for (var i = 0; i < array.length; i++) {
            var task = array[i];
            var tr = document.createElement('tr');
            tr.id = idName + task.id;
            tr.innerHTML = '<td>' + task.id + '</td><td>' + task.task + '</td><td>' + task.priority + '</td><td>' + task.deadline + '</td>';
            tbody.appendChild(tr);
        }
    }
}

