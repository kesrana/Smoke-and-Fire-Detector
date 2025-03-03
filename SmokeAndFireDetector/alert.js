const express = require("express");
const router = new express.Router();
// const { testingEmail } = require("../emails/email");

// Variables to hold the values for each sensor
let TMP36Value = 0;
let MQ2Value = 0;
let MQ7Value = 0;
let MQ135Value = 0;
let TCRT5000Value = 0;

// Route to update the value of TMP36 sensor
router.post("/alert/TMP36", async (req, res) => {
    try {
        const newValue = req.body.newValue;
        if (newValue !== undefined) {
            TMP36Value = newValue;
            res.status(201).send(`TMP36 variable updated to ${newValue}`);
        } else {
            res.status(400).send("No new value provided");
        }
    } catch (e) {
        res.status(400).send(e);
        console.log(e);
    }
});

// Route to get the value of TMP36 sensor
router.get("/alert/TMP36", (req, res) => {
    res.send({ TMP36Value });
});

// Similar routes for other sensors
router.post("/alert/MQ2", async (req, res) => {
    try {
        const newValue = req.body.newValue;
        if (newValue !== undefined) {
            MQ2Value = newValue;
            res.status(201).send(`MQ2 variable updated to ${newValue}`);
        } else {
            res.status(400).send("No new value provided");
        }
    } catch (e) {
        res.status(400).send(e);
        console.log(e);
    }
});

router.get("/alert/MQ2", (req, res) => {
    res.send({ MQ2Value });
});

// Repeat the same pattern for other sensors (MQ7, MQ135, TCRT5000)

// MQ7
router.post("/alert/MQ7", async (req, res) => {
    try {
        const newValue = req.body.newValue;
        if (newValue !== undefined) {
            MQ7Value = newValue;
            res.status(201).send(`MQ7 variable updated to ${newValue}`);
        } else {
            res.status(400).send("No new value provided");
        }
    } catch (e) {
        res.status(400).send(e);
        console.log(e);
    }
});

router.get("/alert/MQ7", (req, res) => {
    res.send({ MQ7Value });
});

// MQ135
router.post("/alert/MQ135", async (req, res) => {
    try {
        const newValue = req.body.newValue;
        if (newValue !== undefined) {
            MQ135Value = newValue;
            res.status(201).send(`MQ135 variable updated to ${newValue}`);
        } else {
            res.status(400).send("No new value provided");
        }
    } catch (e) {
        res.status(400).send(e);
        console.log(e);
    }
});

router.get("/alert/MQ135", (req, res) => {
    res.send({ MQ135Value });
});

// TCRT5000
router.post("/alert/TCRT5000", async (req, res) => {
    try {
        const newValue = req.body.newValue;
        if (newValue !== undefined) {
            TCRT5000Value = newValue;
            res.status(201).send(`TCRT5000 variable updated to ${newValue}`);
        } else {
            res.status(400).send("No new value provided");
        }
    } catch (e) {
        res.status(400).send(e);
        console.log(e);
    }
});

router.get("/alert/TCRT5000", (req, res) => {
    res.send({ TCRT5000Value });
});

module.exports = router;
