(function($) {
    Drupal.behaviors.country_state = {
        attach: function (context, settings) {
            $("select[name='state']").html('<option value="All">--ANY--</option>');

            $( "select[name='country']" ).change(function() {
                // Get selected country
                var selecred_country = $( "select[name='country'] option:selected" ).val();
                $.post('/country-state/get-states/' + selecred_country,{country: selecred_country},
                    function (data) {

                        var states = data.states;

                        var select = $("select[name='state']");
                        var options;
                        for(var value in states){
                            option = '<option value='+ value +'>' + states[value] + '</option>';
                            options += option;
                        }
                        select.html(options);

                    },"json"
                );

            });

        }
    };
})(jQuery);
