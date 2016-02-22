/**
 * Created by alfie on 2/22/16.
 */


var hostname = "";
var reportPage = "report";

function submit(){
    console.log("post!!");
    var content = $("#post-text");
    var responses = {};

    $('.response').each(function(i, obj){
        responses[obj.id] = obj.input;
    });

    $.post(hostname + "/" + "post_debrief", {"post_text": content.val()})
        .done(function(data){
        });
}

function getInfo(){
    $.get(hostname + "/" + reportPage)
        .done(function(data){
            data = JSON.parse(data);
            //console.log("hihihi")
            console.log(data);
            console.log('yeah');

            //if (1||data.GameOver == "false"){
                // get data
                var time=data.TotalTime;
                var score=data.Score;
                var patientInfo=data.PatientInfo;
                console.table(patientInfo);
                var patientStatus=data.PatientStatus;

                //// put data on the webpage
                //$('#score').innerHTML = score;
                //$('#time').innerHTML = time;
                //var patients = $('#patients');
                //var patient = $('<tr></tr>');
                //patient.append($('<td>'+ patientInfo.name +'</td>'));
                //patient.append($('<td>'+ patientInfo.gender +'</td>'));
                //patient.append($('<td>'+ patientInfo.age +'</td>'));
                //patient.append($('<td>'+ patientInfo.height +'</td>'));
                //patient.append($('<td>'+ patientInfo.weight +'</td>'));
                //patient.append($('<td>'+ patientStatus +'</td>'));
                //
                //patients.append(patient);
            //}
            //for (var i= 0; i< data.questions.length; i++){
            //    //console.log(i)
            //    var post = data.questions[i];
            //    var pid = parseInt(post.id);
            //    if (pid > max_id){
            //        max_id = pid
            //    }
            //    var new_post = $(post.html);
            //    if (typeof postcomment !== 'undefined'){
            //        commentDiv = $('<button class="btn btn-lg btn-primary btn-block plain" id="comment-btn" name="postID" value='+post.id+'>comment</button>');
            //        commentDiv.click(comment_grumblr);
            //        new_post.append(commentDiv);
            //    }
            //    //console.log(post.comments)
            //    list.prepend(new_post);
            //}
        });
}

$(document).ready(function(){
    $("#submit_btn").click(submit);
      // CSRF set-up copied from Django docs
      //function getCookie(name) {
      //  var cookieValue = null;
      //  if (document.cookie && document.cookie != '') {
      //      var cookies = document.cookie.split(';');
      //      for (var i = 0; i < cookies.length; i++) {
      //          var cookie = jQuery.trim(cookies[i]);
      //          // Does this cookie string begin with the name we want?
      //          if (cookie.substring(0, name.length + 1) == (name + '=')) {
      //              cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
      //              break;
      //          }
      //      }
      //  }
      //  return cookieValue;
      //}
      //var csrftoken = getCookie('csrftoken');
      //$.ajaxSetup({
      //  beforeSend: function(xhr, settings) {
      //      xhr.setRequestHeader("X-CSRFToken", csrftoken);
      //  }
      //});
    console.log("ready");
    getInfo();
    console.log("yes");
    //window.setInterval(updateStream, 5000);
});