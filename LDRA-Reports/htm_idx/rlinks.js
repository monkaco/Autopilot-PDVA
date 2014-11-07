var CurrentExtension = wfExtArray[0];


function SetCurrentExtension(n)
{
   CurrentExtension = wfExtArray[n];
}


// Get the status of this result file
function check_link(Arr)
{
   return Arr[parent.CurrWork];
}


function MakeFilename(stem, ext_type)
{
   var buffStr = new String(parent.parent.frames[1].location);
   var ret = stem + "." + CurrentExtension;
   var lstr = new String(CurrentExtension);

   if ((lstr.indexOf(".htm") == -1) && (lstr.indexOf(".png") == -1) &&
       (lstr.indexOf(".txt") == -1) && (lstr.indexOf(".rtf") == -1))
   {
       // Report can be generated with .txt or .htm extension appended
       if (ext_type == 3 ||
          (ext_type == 1 && (parent.parent.AddTxt)))
       {
          ret = ret + "." + "txt";
       }
       else if (ext_type == 2)
       {
          ret = ret + "." + "htm";
       }      
   }
   return ret;
}


// Keep a record of which file we are looking at
function setwkindex(workname)
{
   var len;
   // get the path and stem
   var str_arr = workname.split(".");
   flowgraphs(str_arr);

   parent.CurrFileInd = str_arr[0] + ".ind.htm";
}


function MakeLink(stem,modnum,langext,ResArr)
{
   var workstem;
   var lnk = "";
   var ext_type;
   if (modnum == -1)
   {
      workstem = stem;
   }
   else
   {
      workstem = stem + "_" + modnum;
   }
   ext_type = check_link(ResArr)
   if (ext_type > 0)
   {
      lnk = "<h4><CENTER> <A HREF = '" + MakeFilename(workstem, ext_type) +
            "' target='rFrame' onClick='setwkindex(this.href); top.rFrame.focus();'>" + stem + "." + langext + "</A></h4></CENTER> "
   }
   return lnk
}

