package org.cocos2dx.lib;

import java.io.File;
import java.io.FileInputStream;

public class GameControllerUtils {

<<<<<<< HEAD
    public static void ensureDirectoryExist(String path){
        
        File sdkDir = new File(path);
        if(!sdkDir.exists()){
            sdkDir.mkdirs();
        }
    }
    
    public static String readJsonFile(String filePath) {

        File file = new File(filePath);     
        
=======
	public static void ensureDirectoryExist(String path){
		
		File sdkDir = new File(path);
		if(!sdkDir.exists()){
			sdkDir.mkdirs();
		}
	}
	
	public static String readJsonFile(String filePath) {

		File file = new File(filePath);		
		
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        if (!file.exists()){
            return null;
        }
        
        try {

            FileInputStream is = new FileInputStream(file);;

            int size = is.available();
            byte[] buffer = new byte[size];

            is.read(buffer);
            is.close();

            String jsonstr = new String(buffer, "UTF-8");

            return jsonstr;
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }
}
