let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#reset");
let newGameBtn = document.querySelector("#new-btn"); 
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

let turnO = true; //player O if true else player X
let count = 0;

//store winning patterns in array
let winpatterns =[
    [0, 1, 2],
    [0, 3, 6],
    [0, 4, 8],
    [1, 4, 7],
    [2, 5, 8],
    [2, 4, 6],
    [3, 4, 5],
    [6, 7, 8]
];

boxes.forEach((box) =>{
    box.addEventListener("click", ()=>{
        console.log("box was clicked");
        if(turnO){
            box.innerText = "O";
            box.style.color = "red";
            turnO = false;
            
        }
        else{
            box.innerText = "X";
            box.style.color = "blue";
            turnO = true;
        }
        box.disabled = true;
        count++;

        let isWinner = checkWinner();

        if (count === 9 && !isWinner) {
            draw();
        }
    });
});

const disableboxes = () => {
    for(let box of boxes){
        box.disabled  = true;
    }
};

const enableboxes = () => {
    for(let box of boxes){
        box.disabled  = false;
        box.innerText = "";
    }
};

const showWinner = (winner) =>{
    msg.innerText = `Congratulations! Winner is ${winner}`;
    msgContainer.classList.remove("hide");
    disableboxes();
};

const draw = ()=>{
    msg.innerText = `Match Draw`;
    msgContainer.classList.remove("hide");
    disableboxes();
}
const checkWinner = ()=> {
    
    for (let pat of winpatterns){
        /*console.log(pat[0], pat[1], pat[2]);      to check boxes and patterns
        console.log(
        boxes[pat[0]].innerText,
        boxes[pat[1]].innerText, 
        boxes[pat[2]].innerText
         );*/
        let pos1 = boxes[pat[0]].innerText;
        let pos2 = boxes[pat[1]].innerText;
        let pos3 = boxes[pat[2]].innerText
        
        if(pos1 !="" && pos2 !="" && pos3 !=""){
            if(pos1===pos2 && pos2===pos3){
                console.log("winner!", pos1);
                showWinner(pos1);
                return true;
            }
        }
    }
};

const resetGame = ()=>{
    turnO = true;
    count = 0;
    enableboxes();
    msgContainer.classList.add("hide");

};

newGameBtn.addEventListener("click", resetGame);
resetBtn.addEventListener("click", resetGame);