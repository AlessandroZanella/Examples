
function iterateAllKeysObject()
{
    let obj = { name: "Paolino", surname: "Paperino" };

    for (let key of Object.keys(obj)) {
        console.log(key);
    }
}

iterateAllKeysObject();