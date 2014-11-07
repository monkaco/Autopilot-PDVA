var temp_str ='<img src="file:..//images/';
var base_str ='<a href="file:./';
function TBLaunchit(eParam, eOtherParam)
{
var RunLine;
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\TBbrowse.exe' + '"| '
 + '"' + eParam + '"'   + ' -Start=' + eOtherParam + ' ';
LDRATBLaunch.ExecuteIt(RunLine);
}

function TBBrowseit_2(eParam, eOtherParam, sourceName)
{
var RunLine;
if (sourceName != undefined)
{
   tbbrowseSrc = ' -SourceModule=' + sourceName + '';
}
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\tbbrowse.exe' + '"| '
 + '"' + eParam + '"'   + ' -Start=' + eOtherParam + ' -End=' + eOtherParam + ' -Language=2' + tbbrowseGlh + tbbrowseSrc + tbbrowseXrefSet +'';
LDRATBLaunch.ExecuteIt(RunLine);
}

function TBBrowseit_h_2(eParam, eOtherParam, h_start_end, sourceName)
{
var RunLine;
if (sourceName != undefined)
{
   tbbrowseSrc = ' -SourceModule=' + sourceName + '';
}
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\tbbrowse.exe' + '"| '
 + '"' + eParam + '"'   + ' -Start=' + eOtherParam + ' -End=' + eOtherParam + ' -Language=2' + tbbrowseGlh + tbbrowseSrc + tbbrowseXrefSet +' -IncludeLines=' + h_start_end + '';
LDRATBLaunch.ExecuteIt(RunLine);
}

function TBBrowseit_6(eParam, eOtherParam, sourceName)
{
var RunLine;
if (sourceName != undefined)
{
   tbbrowseSrc = ' -SourceModule=' + sourceName + '';
}
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\tbbrowse.exe' + '"| '
 + '"' + eParam + '"'   + ' -Start=' + eOtherParam + ' -End=' + eOtherParam + ' -Language=6' + tbbrowseGlh + tbbrowseSrc + tbbrowseXrefSet +'';
LDRATBLaunch.ExecuteIt(RunLine);
}

function TBBrowseit_h_6(eParam, eOtherParam, h_start_end, sourceName)
{
var RunLine;
if (sourceName != undefined)
{
   tbbrowseSrc = ' -SourceModule=' + sourceName + '';
}
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\tbbrowse.exe' + '"| '
 + '"' + eParam + '"'   + ' -Start=' + eOtherParam + ' -End=' + eOtherParam + ' -Language=6' + tbbrowseGlh + tbbrowseSrc + tbbrowseXrefSet +' -IncludeLines=' + h_start_end + '';
LDRATBLaunch.ExecuteIt(RunLine);
}

function TBBrowseit_var_para (eParam, eOtherParam, eOtherParam2)
{
var RunLine;
RunLine=  '"' + 'C:\\LDRA_Toolsuite\\tbbrowse.exe' + '"| '
 + '"' + eParam + '"' + " -" + eOtherParam + '=' + '"' +  eOtherParam2 + '"'  + '' ;
LDRATBLaunch.ExecuteIt(RunLine);
}

var ie_ver = getIE_ver();
function getIE_ver()
{
var ret = -1;
if (navigator.appName == 'Microsoft Internet Explorer')
{
var ua = navigator.userAgent;
var re = new RegExp("MSIE ([0-9]{1,}[.0-9]{0,})");
if (re.exec(ua) != null)
{
ret = parseFloat( RegExp.$1 );
}
}
return ret;
}
