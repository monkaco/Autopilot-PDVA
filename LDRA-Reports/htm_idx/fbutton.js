
var array_size = 39;

var base = new Array();

normal   = new MakeArray(array_size);
over     = new MakeArray(array_size);
outlined = new MakeArray(array_size);

var index = 1;
base[index++]  = "refcode.gif";
base[index++]  = "lcsaj_rep.gif";
base[index++]  = "lcsaj_planner_ascii.gif";
base[index++]  = "lcsaj_planner_html.gif";
base[index++]  = "dflow.gif";
base[index++]  = "xref.gif";
base[index++]  = "infoflow.gif";
base[index++]  = "doa_asc.gif";
base[index++]  = "doa_htm.gif";
base[index++]  = "test_planner.gif";
base[index++]  = "dyn_cov.gif";
base[index++]  = "dyn_cov_asc.gif";
base[index++]  = "dyn_cov_htm.gif";
base[index++]  = "profile.gif";
base[index++]  = "dyndset.gif";
base[index++]  = "dyn_dflow_cov.gif";
base[index++]  = "dyn_dflow_cov_htm.gif";
base[index++]  = "metrics_asc.gif";
base[index++]  = "metrics_htm.gif";
base[index++]  = "quality_rep_asc.gif";
base[index++]  = "quality_rep_htm.gif";
base[index++]  = "class_hier.gif";
base[index++]  = "pro_glo.gif";
base[index++]  = "user_type.gif";
base[index++]  = "static_cgraph.gif";
base[index++]  = "curr_dyn_cgraph.gif";
base[index++]  = "comb_dyn_cgraph.gif";
base[index++]  = "kiviat.gif";
base[index++]  = "class_hier_gr.gif";
base[index++]  = "static_fgraph.gif";
var showflow = index - 1;
base[index++]  = "curr_dyn_fgraph.gif";
var show_l_flow = index - 1;
base[index++]  = "comb_dyn_fgraph.gif";
var show_d_flow = index - 1;
base[index++]  = "regression.gif";
var show_regression = index - 1;
base[index++]  = "a_scope.gif";
base[index++]  = "overv_ascii.gif";
base[index++]  = "overv_html.gif";
base[index++]  = "annot_code.gif";
var max_result = index - 1;
base[index++]  = "set_index.gif";
base[index++]  = "home_img.gif";


InitImageArrays ();

var highlighted;
var highlighted_image;


function InitImageArrays ()
{
   for (var i = 1; i<= array_size; i++)
   {
      normal[i].src = "../images/normal/" + base[i];
      over[i].src = "../images/over/" + base[i];
      outlined[i].src = "../images/outlined/" + base[i];
   }
   return this;
   
}

function msclick(num,pos)
{
   document.images[highlighted].src = normal[highlighted_image].src;
   document.images[pos].src = outlined[num].src;
   highlighted = pos;
   highlighted_image = num;

   if ((highlighted_image == showflow) || (highlighted_image == show_d_flow) ||
       (highlighted_image == show_l_flow))
   {
      set_fg_links(document.all.FlowList.all, "", highlighted_image);

      document.all.FlowList.style.display = "";
      document.all.Buttons.style.display = "none";
      document.all.RegressList.style.display = "none";
   }
   else if ((highlighted_image == show_regression))
   {
      set_fg_links(document.all.RegressList.all, "", highlighted_image);

      document.all.RegressList.style.display = "";
      document.all.Buttons.style.display = "none";
      document.all.FlowList.style.display = "none";
   }
   else
   {
      document.all.addheader.innerText = "Results";
      document.all.Buttons.style.display = "";
      document.all.FlowList.style.display = "none";
      document.all.RegressList.style.display = "none";
   }
   if (highlighted_image <= max_result)
   {
      parent.CurrWork = highlighted_image - 1;
   }
   
}


// First load flag
var first_button = 1;

function ButtonImgStr(index, pos, height)
{
   var ret;

   if (((first_button == 1) && (0 == parent.CurrWork)) ||
       (index == array_size))
   {
      // Highlight this one
      ret = "<IMG SRC='" +  outlined[index].src + "'border=0 width='170' height='" + height + "'></A> </CENTER>"
      highlighted_image = index;
      highlighted = pos;
      first_button = 0;
   }
   else
   {
      ret = "<IMG SRC='" +  normal[index].src + "'border=0 width='170' height='" + height + "'></A> </CENTER>"
      highlighted_image = array_size
      highlighted = 1;
   }
   return ret;
}

