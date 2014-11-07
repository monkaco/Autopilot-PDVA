function popup(mylink, windowname)

{

  if (! window.focus && window.opener)
  {
    return true;
  }


var href;
var temp;

  if (typeof(mylink)=='string')
  {

    href=mylink;

  }
 else
  {
    href=mylink.href;

    temp = window.open(href, windowname, 'width=600, height=300,scrollbars=yes');
    
    temp.focus();

    return false;
  }
}

function targetopener(mylink, closeme, closeonly)
{
if (! (window.focus && window.opener))     return true;
if (! closeonly)                           window.opener.location.href=mylink.href;
window.blur();
window.opener.focus();
if (closeme)                               window.close();
return false;

}

