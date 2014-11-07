// Declare 3 arrays of images. These contain firstly the normal
// button images, then those images that appear when the mouse
// hovers over a button and finally those images used to indicate
// which button is currently selected.
//
normal   = new MakeArray(28);
over     = new MakeArray(28);
outlined = new MakeArray(28);

normal[1].src  = "../images/normal/overv_html.gif";
normal[2].src  = "../images/normal/quality_rep_htm.gif";
normal[3].src  = "../images/normal/quality_rep_asc.gif";
normal[4].src  = "../images/normal/metrics_asc.gif";
normal[5].src  = "../images/normal/metrics_htm.gif";
normal[6].src  = "../images/normal/infoflow_oview.gif";
normal[7].src  = "../images/normal/doa_asc.gif";
normal[8].src  = "../images/normal/doa_htm.gif";
normal[9].src  = "../images/normal/static_cgraph.gif";
normal[10].src  = "../images/normal/dyn_oview.gif";
normal[11].src  = "../images/normal/dyn_oview.gif";
normal[12].src  = "../images/normal/dyn_dflow_cov.gif";
normal[13].src  = "../images/normal/dyn_dflow_cov_htm.gif";
normal[14].src  = "../images/normal/curr_dyn_cgraph.gif";
normal[15].src  = "../images/normal/comb_dyn_cgraph.gif";
normal[16].src  = "../images/normal/kiviat.gif";
normal[17].src  = "../images/normal/class_hier_gr.gif";
normal[18].src  = "../images/normal/oo_class_kiv.gif";
normal[19].src  = "../images/normal/class_hier.gif";
normal[20].src  = "../images/normal/pro_glo.gif";
normal[21].src  = "../images/normal/user_type.gif";
normal[22].src  = "../images/normal/gxref.gif";
normal[23].src  = "../images/normal/integrep.gif";
normal[24].src  = "../images/normal/overv_ascii.gif";
normal[25].src  = "../images/normal/a_scope.gif";
normal[26].src  = "../images/normal/regression.gif";
normal[27].src  = "../images/normal/set_index.gif";
normal[28].src  = "../images/normal/home_img.gif";

over[1].src  = "../images/over/overv_html.gif";
over[2].src  = "../images/over/quality_rep_htm.gif";
over[3].src  = "../images/over/quality_rep_asc.gif";
over[4].src  = "../images/over/metrics_asc.gif";
over[5].src  = "../images/over/metrics_htm.gif";
over[6].src  = "../images/over/infoflow_oview.gif";
over[7].src  = "../images/over/doa_asc.gif";
over[8].src  = "../images/over/doa_htm.gif";
over[9].src  = "../images/over/static_cgraph.gif";
over[10].src  = "../images/over/dyn_oview.gif";
over[11].src  = "../images/over/dyn_oview.gif";
over[12].src  = "../images/over/dyn_dflow_cov.gif";
over[13].src  = "../images/over/dyn_dflow_cov_htm.gif";
over[14].src  = "../images/over/curr_dyn_cgraph.gif";
over[15].src  = "../images/over/comb_dyn_cgraph.gif";
over[16].src  = "../images/over/kiviat.gif";
over[17].src  = "../images/over/class_hier_gr.gif";
over[18].src  = "../images/over/oo_class_kiv.gif";
over[19].src  = "../images/over/class_hier.gif";
over[20].src  = "../images/over/pro_glo.gif";
over[21].src  = "../images/over/user_type.gif";
over[22].src  = "../images/over/gxref.gif";
over[23].src  = "../images/over/integrep.gif";
over[24].src  = "../images/over/overv_ascii.gif";
over[25].src  = "../images/over/a_scope.gif";
over[26].src  = "../images/over/regression.gif";
over[27].src  = "../images/over/set_index.gif";
over[28].src  = "../images/over/home_img.gif";

outlined[1].src  = "../images/outlined/overv_html.gif";
outlined[2].src  = "../images/outlined/quality_rep_htm.gif";
outlined[3].src  = "../images/outlined/quality_rep_asc.gif";
outlined[4].src  = "../images/outlined/metrics_asc.gif";
outlined[5].src  = "../images/outlined/metrics_htm.gif";
outlined[6].src  = "../images/outlined/infoflow_oview.gif";
outlined[7].src  = "../images/outlined/doa_asc.gif";
outlined[8].src  = "../images/outlined/doa_htm.gif";
outlined[9].src  = "../images/outlined/static_cgraph.gif";
outlined[10].src  = "../images/outlined/dyn_oview.gif";
outlined[11].src  = "../images/outlined/dyn_oview.gif";
outlined[12].src  = "../images/outlined/dyn_dflow_cov.gif";
outlined[13].src  = "../images/outlined/dyn_dflow_cov_htm.gif";
outlined[14].src  = "../images/outlined/curr_dyn_cgraph.gif";
outlined[15].src  = "../images/outlined/comb_dyn_cgraph.gif";
outlined[16].src  = "../images/outlined/kiviat.gif";
outlined[17].src  = "../images/outlined/class_hier_gr.gif";
outlined[18].src  = "../images/outlined/oo_class_kiv.gif";
outlined[19].src  = "../images/outlined/class_hier.gif";
outlined[20].src  = "../images/outlined/pro_glo.gif";
outlined[21].src  = "../images/outlined/user_type.gif";
outlined[22].src  = "../images/outlined/gxref.gif";
outlined[23].src  = "../images/outlined/integrep.gif";
outlined[24].src  = "../images/outlined/overv_ascii.gif";
outlined[25].src  = "../images/outlined/a_scope.gif";
outlined[26].src  = "../images/outlined/regression.gif";
outlined[27].src  = "../images/outlined/set_index.gif";
outlined[28].src  = "../images/outlined/home_img.gif";

// Variable 'highlighted' indicates which button in the
// menu currently has an orange border highlight
//
var highlighted;
var highlighted_image;

var set_ind = 27;
var oo_kiv = 18;
var show_regression= 26;

// Function to detect when a button is clicked and swap
// button images accordingly.
//
function msclick(num,pos)
{
   document.images[highlighted].src = normal[highlighted_image].src;
   document.images[pos].src = outlined[num].src;

   highlighted = pos;
   highlighted_image = num;

   if (highlighted_image == oo_kiv)
   {
      document.all.OOKivList.style.display = "";
      document.all.Buttons.style.display = "none";
      document.all.RegressList .style.display = "none";
   }
   else if ((highlighted_image == show_regression))
   {
      document.all.RegressList .style.display = "";
      document.all.OOKivList.style.display = "none";
      document.all.Buttons.style.display = "none";
   }
   else
   {
      document.all.OOKivList.style.display = "none";
      document.all.RegressList .style.display = "none";
      document.all.Buttons.style.display = "";
   }
}


// First load flag
var first_set_button = 1;

function ButtonImgStr(index ,pos, height)
{
   var ret;
   if (index == (set_ind + 1))
   {
      height = 75;
   }
   if (first_set_button == 1)
   {
      ret = "<IMG SRC='" +  outlined[index].src + "'border=0 width='170' height='" + height + "'></A> </CENTER>"
      highlighted_image = index;
      highlighted = pos;
      first_set_button = 0;
   }
   else
   {
      ret = "<IMG SRC='" +  normal[index].src + "'border=0 width='170' height='" + height + "'></A> </CENTER>"
   }
   return ret;
}

