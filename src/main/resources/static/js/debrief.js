/**
 * Created by alfie on 2/22/16.
 */


var hostname = "";
var reportPage = "report";

var app = angular.module('screen-based-simulator-app', []);

app.controller('screen-based-simulator-controller', function ($scope, $http, $interval) {
  $scope.patient = {
    "GameOver": false,
    "TotalTime":0.01,
    "Score": 65.828214,
    "PatientInfo": {
      "patientHash":"lqsgrwjj",
      "name":"egkmf",
      "gender":"FEMALE",
      "age":39,
      "weight":16.741721,
      "height":10.710425,
      "status":"good"
    },
    "PatientStatus":{
      "heart_rate":51.901133599877,
      "respiration_rate":78.06337522316613,
      "systolic_arterial_pressure":73.87969344417648,
      "diastolic_arterialpressure":112.43059018359946,
      "oxygen_saturation":98.6743920641709
    }
  };
  function update() {
      $.get(hostname + "/" + reportPage)
        .done(function(data){
            data = JSON.parse(data);
            //console.log("hihihi")
            console.log(data);
            console.log('yeah');

            //if (1||data.GameOver == "false"){
                // get data
                $scope.patient = data;

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
    $http.get('/report').then(function(res){
        console.log(res.data);
        $scope.patient = res.data;
      });
  }

  $interval(update, 1000);
});


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
    //$.get(hostname + "/" + reportPage)
    //    .done(function(data){
    //        data = JSON.parse(data);
    //        //console.log("hihihi")
    //        console.log(data);
    //        console.log('yeah');
    //
    //        //if (1||data.GameOver == "false"){
    //            // get data
    //            var time=data.TotalTime;
    //            var score=data.Score;
    //            var patientInfo=data.PatientInfo;
    //            console.table(patientInfo);
    //            var patientStatus=data.PatientStatus;
    //
    //            //// put data on the webpage
    //            //$('#score').innerHTML = score;
    //            //$('#time').innerHTML = time;
    //            //var patients = $('#patients');
    //            //var patient = $('<tr></tr>');
    //            //patient.append($('<td>'+ patientInfo.name +'</td>'));
    //            //patient.append($('<td>'+ patientInfo.gender +'</td>'));
    //            //patient.append($('<td>'+ patientInfo.age +'</td>'));
    //            //patient.append($('<td>'+ patientInfo.height +'</td>'));
    //            //patient.append($('<td>'+ patientInfo.weight +'</td>'));
    //            //patient.append($('<td>'+ patientStatus +'</td>'));
    //            //
    //            //patients.append(patient);
    //        //}
    //        //for (var i= 0; i< data.questions.length; i++){
    //        //    //console.log(i)
    //        //    var post = data.questions[i];
    //        //    var pid = parseInt(post.id);
    //        //    if (pid > max_id){
    //        //        max_id = pid
    //        //    }
    //        //    var new_post = $(post.html);
    //        //    if (typeof postcomment !== 'undefined'){
    //        //        commentDiv = $('<button class="btn btn-lg btn-primary btn-block plain" id="comment-btn" name="postID" value='+post.id+'>comment</button>');
    //        //        commentDiv.click(comment_grumblr);
    //        //        new_post.append(commentDiv);
    //        //    }
    //        //    //console.log(post.comments)
    //        //    list.prepend(new_post);
    //        //}
    //    });
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