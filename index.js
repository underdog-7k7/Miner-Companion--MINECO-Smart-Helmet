$(document).ready(function ()
        {
            GetData();
            $(".btn1").click(()=>{
                $('#txtField1').val("");
                $('#txtField2').val("");
                $('#txtField3').val("");
                $('#txtField4').val("");
            });
        });

        function GetData()
        {
            var url = 'https://api.thingspeak.com/channels/1921840/feeds.json?key=KRQCVPISIL3CQVS8&results=1';
            $.ajax
            ({
                url: url,
                type: 'GET',
                contentType: "application/json",
                //dataType: "json",
                //crossDomain: true,
                success: function (data, textStatus, xhr) {
                    console.log(data);
                    $.each(data, function (i, item) {
                        if (i == 'feeds') {
                            var ubound = item.length;
                            if(item[ubound - 1].field1 != null){
                                $('#txtField1').val(item[ubound - 1].field1);
                            }
                            if(item[ubound - 1].field2 != null){
                                $('#txtField2').val(item[ubound - 1].field2);
                            }
                            if(item[ubound - 1].field3 != null){
                                $('#txtField3').val(item[ubound - 1].field3);
                            }
                            if(item[ubound - 1].field4 != null){
                                $('#txtField4').val(item[ubound - 1].field4);
                            }
                            if(item[ubound - 1].field4 > 30){
                                alert("Evacuate High Gas Concentration")
                            }
                            if(item[ubound - 1].field4 > 15){
                                alert("Evacuate High Temprature")    
                            }   
                        }
                    });
                },
                error: function (xhr, textStatus, errorThrown) {
                    alert(errorThrown);
                }
            });

            setTimeout(GetData, 100);
        }