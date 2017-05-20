// demo.js

(function(ext) {
    var device = null;
    
	var levels = {
		HIGH:1,
		LOW:0
	};
    
	ext.resetAll = function(){};
	
	ext.whenKeyPressed = function(key){
		
	};
	
	ext.whenKeyReleased = function(key){
		
	};
	
	ext.setupIR = function(pin) {
        
    };

    function processData(bytes) {
        trace(bytes);
    }

    // Extension API interactions
    var potentialDevices = [];
    ext._deviceConnected = function(dev) {
        potentialDevices.push(dev);

        if (!device) {
            tryNextDevice();
        }
    }

    function tryNextDevice() {
        // If potentialDevices is empty, device will be undefined.
        // That will get us back here next time a device is connected.
        device = potentialDevices.shift();
        if (device) {
            device.open({ stopBits: 0, bitRate: 115200, ctsFlowControl: 0 }, deviceOpened);
        }
    }

    function deviceOpened(dev) {
        if (!dev) {
            // Opening the port failed.
            tryNextDevice();
            return;
        }
        device.set_receive_handler('rover',function(data) {
            processData(data);
        });
    };

    ext._deviceRemoved = function(dev) {
        if(device != dev) return;
        device = null;
    };

    ext._shutdown = function() {
        if(device) device.close();
        device = null;
    };

    ext._getStatus = function() {
        if(!device) return {status: 1, msg: 'Arduino Rover disconnected'};
        return {status: 2, msg: 'Arduino Rover connected'};
    }

    var descriptor = {};
	ScratchExtensions.register('rover', descriptor, ext, {type: 'serial'});
})({});
