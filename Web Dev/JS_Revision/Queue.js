function queue()
{
    let que = [];
    f(op, value)
    {
        if(op = "insert")
            que.push(value);
        else if(op == "out")
            que.shift();
        else if(op == "show")
            console.log(que);
    }
}

queue();

f("insert", 2);
f("insert", 4);
f("insert", 5);
f("insert", 1);
f("show");
f("out");
f("show");
