var external0 = null;
var external_1000 = null;
var external_1001 = null;
var external_1002 = null;
var external_1003 = null;
var external_1004 = null;
var external_1005 = null;
var external_1006 = null;
var external_1007 = null;
var external_1009 = null;



String.prototype.format = function() {  
    if(arguments.length == 0) return this;  
    var obj = arguments[0];  
    var s = this;  
    for(var key in obj) {  
        s = s.replace(new RegExp("\\{\\{" + key + "\\}\\}", "g"), obj[key]);  
    }  
    return s;  
}  

new QWebChannel(qt.webChannelTransport,
	function(channel) {
		external0 = channel.objects.external0;
		external_1000 = channel.objects.external_1000;
external_1001 = channel.objects.external_1001;
external_1002 = channel.objects.external_1002;
external_1003 = channel.objects.external_1003;
external_1004 = channel.objects.external_1004;
external_1005 = channel.objects.external_1005;
external_1006 = channel.objects.external_1006;
external_1007 = channel.objects.external_1007;
external_1009 = channel.objects.external_1009;

	}
);

function appendHtml0(msg){
	$("#placeholder").append(external0.msgRHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};

function recvHtml_1000(msg){
	$("#placeholder").append(external_1000.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1001(msg){
	$("#placeholder").append(external_1001.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1002(msg){
	$("#placeholder").append(external_1002.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1003(msg){
	$("#placeholder").append(external_1003.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1004(msg){
	$("#placeholder").append(external_1004.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1005(msg){
	$("#placeholder").append(external_1005.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1006(msg){
	$("#placeholder").append(external_1006.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1007(msg){
	$("#placeholder").append(external_1007.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
function recvHtml_1009(msg){
	$("#placeholder").append(external_1009.msgLHtmlTmpl.format(msg));
	window.scrollTo(0,document.body.scrollHeight); ;  
};
