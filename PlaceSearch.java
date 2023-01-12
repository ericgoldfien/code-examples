package com.example.chooseforme;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;

import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;


public class PlaceSearch {
	// uses http request to get places results
	
	HttpClient client;
	HttpGet request;
	HttpResponse response;
	String results;
	public String sendRequest(String uriString) throws Exception {
		results = "";
		
		try {
			String inputKey = "1234";
			
			client = new DefaultHttpClient();
			URI uri = new URI(uriString);
			request = new HttpGet();
			request.setURI(uri);
			
			
			response = client.execute(request);
			results = "4"; ///////////////

		} catch(Exception e) {
			//results = "5"; ///////////////
			e.printStackTrace();
			results = "?" + e.toString();
						
		}
	}
			
			
			
			
			
			
			//results = uri.toString();
			
			
			/*
			int status = response.getStatusLine().getStatusCode();
			
			if (status == 200) {
				
			} else {
				
			}
			*/
			
			
			String responseString = response.toString();
			//results = "6"; ///////////////
			// turn response into a string
			BufferedReader in = new BufferedReader(new InputStreamReader(response.getEntity().getContent()));
			StringBuffer stringBuffer = new StringBuffer("");
			String line = "" ;
			String newLine = "\n";
			
			// move from bufferedReader to stringBuffer
			line = in.readLine();
			while(line != null && line != "") {
				stringBuffer.append(line + "\n");
				line = in.readLine();
			}
			in.close();
			
			//results = stringBuffer.toString();
			//results = "9"; ///////////////
			return results;
			
			//return responseString;
			
		
		
		
		
	}
}
