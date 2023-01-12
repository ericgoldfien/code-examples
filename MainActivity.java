package com.example.chooseforme;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.ToggleButton;

public class MainActivity extends Activity implements OnClickListener, LocationListener {

	private LocationManager lm;
	String location;
	private String provider = LocationManager.NETWORK_PROVIDER;
	private final String food = "bakery|cafe|food|restaurant|meal_takeaway";
	private final String entertainment = "amusement_park|aquarium|art_gallery|bowling_alley|casino|gym|library|"
			+ "movie_rental|movie_theater|museum|park|spa|stadium|zoo";
	private final String shopping = "bicycle_store|book_store|clothing_store|convenience_store|jewelry_store"
			+ "|electronics_store|pet_store|shoe_store|shopping_mall";
	private final String nightlife = "bar|liqour_store|night_club|casino";
	String types; // = "types=";
	String radius = "radius=1610";
	RadioGroup rg;
	RadioButton rb;
	
	// onCreate
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		lm = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
		
		findViewById(R.id.button1).setOnClickListener(this);
		
		ToggleButton toggle = (ToggleButton) findViewById(R.id.toggleButton1); //display message if toggle pressed
		toggle.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
		    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
		    	radius = "radius=";
		    	if (isChecked) {
		           radius += "20000";	           
		        } else {
		           radius += "1610";
		        }
		    }
		});
	}

	@Override
	public void onLocationChanged(Location arg0) {
		double lat = (double) (arg0.getLatitude());
	    double lng = (double) (arg0.getLongitude());
	    ((TextView)findViewById(R.id.status)).setText("");
	    Button b = (Button)findViewById(R.id.button1);
	    b.setVisibility(0);
		location = "location=" + String.valueOf(lat) + "," + String.valueOf(lng);
	}

	@Override
	public void onProviderDisabled(String arg0) {

		
	    ((TextView)findViewById(R.id.status)).setText
    	("Please enable location services");
		
	}

	@Override
	public void onProviderEnabled(String arg0) {
		// TODO Auto-generated method stub
		lm.requestLocationUpdates( provider, 60000, 100, this);
	    ((TextView)findViewById(R.id.status)).setText
    	("Searching for location");
	}

	@Override
	public void onStatusChanged(String arg0, int arg1, Bundle arg2) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	protected void onResume() {
		super.onResume();
	    lm.requestLocationUpdates(provider, 60000, 0, this);
	    ((TextView)findViewById(R.id.status)).setText
    	("Searching for location...");
	}

	@Override
	protected void onPause() {
	    super.onPause();
	    lm.removeUpdates(this);
	}


	@Override
	public void onClick(View v) {
		Intent getResults = new Intent(MainActivity.this,Results.class); //create intent and package result

		rg = (RadioGroup)findViewById(R.id.radioGroup1);
		int selection = rg.getCheckedRadioButtonId(); //access the text from clicked button
		rb = (RadioButton)findViewById(selection);
		String temp = (String)rb.getText();
		
		// set types string for user's choice
		types = "types=";
		
		if(temp.equals("Dining")){
			types += food;
		}
		if(temp.equals("Entertainment")){
			types += entertainment;
		}
		if(temp.equals("Shopping")){
			types += shopping;
		}
		if(temp.equals("Night Life")){
			types += nightlife;
		}
		if(temp.equals("Any of the above")){
			types = types + food + "|" + entertainment + "|" + shopping + "|" + nightlife;
		}
		
		location = "location=" + "33.99083,118.45917"; ///  remove to use!
		
		// put extras
		getResults.putExtra("location", location); //the gps coordinates in the right format
		getResults.putExtra("radius", radius); // the radius in the right format
		getResults.putExtra("types",types);
		
		// start activity
		startActivity(getResults);
		

		
	}
	

		
	
}
