# Javascript

**注意 **ECMAScript 中函数的参数就是局部变量。

```javascript
function plusTen(num) {
	num += 10;
	return num;
}
function setName(obj) {
	obj.name = "BOBLT";
    return obj;
}
function setName2(obj) {
    obj.name = "Bob";
    obj = new Object();
    obj.name = "Alice";
}
let tt = 2;
let kk = new Object();
let xx = new Object();

console.log(tt); // 2 --- var复制进函数，不改变
console.log(plusTen(tt)); // 12
setName(kk);
console.log(kk.name); // BOBLT --- obj和kk指向相同对象，也同样被改变
setName2(xx);
console.log(xx.name); // Bob --- 函数中参数的值改变之后，原始的引用仍然没变
```

