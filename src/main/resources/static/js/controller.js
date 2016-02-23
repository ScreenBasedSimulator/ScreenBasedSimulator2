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
      "height":10.710425
    },
    "PatientStatus":{
      "heart_rate":51.901133599877,
      "respiration_rate":78.06337522316613,
      "systolic_arterial_pressure":73.87969344417648,
      "diastolic_arterialpressure":112.43059018359946,
      "oxygen_saturation":98.6743920641709
    }
  }
  function update() {
    $http.get('/report').then(function(res){
        console.log(res.data);
        $scope.patient = res.data;
      });
  }
  
  $interval(update, 1000);
});
