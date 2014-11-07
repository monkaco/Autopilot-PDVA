

// Defined in Fbutton.js

var showflow;
var show_l_flow;
var show_d_flow;
var showbars;

// Get the <A> anchor elements of flowgraph list
// and modify them to point to the correct flowgraph
// i.e. static, combined dynamic or last dynamic

function set_fg_links(coll, fg_type, change_header)
{
   var i;
   var str;

   if(change_header == show_d_flow)
   {
      fg_type = "dfg.png";
      document.all.addheader.innerText = "Combined Dynamic Flowgraphs";
   }
   else if(change_header == show_l_flow)
   {
      fg_type = "lfg.png";
      document.all.addheader.innerText = "Current Dynamic Flowgraphs";
   }
   else if(change_header == showflow)
   {
      fg_type = "sfg.png";
      document.all.addheader.innerText = "Static Flowgraphs";
   }
   else if(change_header == show_regression)
   {
      fg_type = "";
      document.all.addheader.innerText = "Regression Reports";
   }

   if (fg_type  != "")
   {
      for (i= 0; i<coll.length; i++)
      {
         if (coll[i].tagName == "A")
         {
            str = coll[i].href.split(".");
            coll[i].href = str[0] + "." + fg_type;
         }
      }
   }
}


function ButtonStr(targ_file,click_number,pos)
{
   var brack_click = "(" + click_number + "," + pos + ");'";
   var focus_click = "(" + click_number + "," + pos + "); top.rFrame.focus();'";
   var msstr = "onmouseover='msover" + brack_click  + "onclick='msclick" + focus_click + "onmouseout='msout" + brack_click;
   var ret = "<CENTER> <A HREF = '" + targ_file + "' target='rFrame'" + msstr + ">";
   return ret;
}


function PicLinkStr(targ_file,link_text)
{
   var ret = "<FONT COLOR='#FF9933'> <LI><A HREF= '";
   ret = ret + targ_file;
   ret = ret + "'TARGET='rFrame' >";
   ret = ret + link_text;
   ret = ret + "</A> </FONT>";
   return ret;
}


function MakeArray(n)
{
   this.length = n;
   for (var i = 1; i<=n; i++)
   {
        this[i] = new Image();
   }
   return this;
}


function msover(num, pos)
{
   if( highlighted != pos )
   {
       document.images[pos].src = over[num].src;
   }
}


function msout(num, pos)
{
   if( highlighted == pos )
   {
      document.images[pos].src = outlined[num].src;
   }
   else
   {
      document.images[pos].src = normal[num].src;
   }
}

